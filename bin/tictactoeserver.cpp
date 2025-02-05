
#include <iostream>
#include <memory>
#include <string>

#include <grpc++/grpc++.h>

#include "protos/tictactoe.pb.h"
#include "protos/tictactoe.grpc.pb.h"

// #include "lib/game.hpp"
#include "lib/board.hpp"
#include "lib/randomplayerchooser.hpp"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using grpc::StatusCode;
using tictactoe_if::Empty;
// using tictactoe::Move;
using tictactoe_if::MoveReply;
using tictactoe_if::StartReply;
using tictactoe_if::TicTacToe;

// Logic and data behind the server's behavior.
class TicTacToeServiceImpl final : public TicTacToe::Service
{
public:
    TicTacToeServiceImpl()
    {
        // game = Game();
        board = Board();
        startingPlayerChooser = RandomStartingPlayerChooser();
    }

    Status StartGame(ServerContext *context, const Empty *request,
                     StartReply *reply) override
    {
        auto startingPlayer = startingPlayerChooser.chooseStartingPlayer();
        std::cout << "Starting player: " << startingPlayer << std::endl;
        currentPlayer = startingPlayer;
        if (currentPlayer == PlayerId::X)
        {
            reply->set_first_player(tictactoe_if::Player::X);
        }
        else
        {
            reply->set_first_player(tictactoe_if::Player::O);
        }
        return Status::OK;
    }

    Status MakeMove(ServerContext *context, const tictactoe_if::Move *request,
                    tictactoe_if::MoveReply *reply) override
    {
        // reply->set_player(tictactoe::Player::X);
        // Check if it is the correct player's turn
        if ((request->player() == tictactoe_if::Player::X && currentPlayer == PlayerId::X) ||
            (request->player() == tictactoe_if::Player::O && currentPlayer == PlayerId::O))
        {
            if (board.makeMove({request->row(), request->col()}, currentPlayer))
            {
                reply->set_valid(true);
            }
            else
            {
                reply->set_valid(false);
            }
        }

        if (board.checkWin(currentPlayer))
        {
            reply->set_game_over(true);
            reply->set_winner(request->player());
        }
        else if (board.isFull())
        {
            reply->set_game_over(true);
        }
        else
        {
            reply->set_game_over(false);
            if (currentPlayer == PlayerId::X)
            {
                currentPlayer = PlayerId::O;
            }
            else
            {
                currentPlayer = PlayerId::X;
            }
        }
        // std::cout << "Received message from client: " << request->name() << std::endl;
        return Status::OK;
    }

private:
    // Game game;
    PlayerId currentPlayer;
    Board board;
    RandomStartingPlayerChooser startingPlayerChooser;
};

void RunServer()
{
    // std::string server_address("0.0.0.0:50051");
    std::string server_address("127.0.0.1:50052");
    TicTacToeServiceImpl service;

    ServerBuilder builder;
    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    // Register "service" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *synchronous* service.
    builder.RegisterService(&service);
    // Finally assemble the server.
    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    // Wait for the server to shutdown. Note that some other thread must be
    // responsible for shutting down the server for this call to ever return.
    server->Wait();
}

int main(int argc, char **argv)
{
    RunServer();

    return 0;
}