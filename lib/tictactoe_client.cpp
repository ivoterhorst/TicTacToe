#include <iostream>

#include "tictactoe_client.hpp"

using tictactoe_if::Empty;
using tictactoe_if::StartReply;

// Constructor with "initialization list"
TicTacToeClient::TicTacToeClient(std::shared_ptr<Channel> channel)
    : stub_(TicTacToe::NewStub(channel)) {}

tictactoe::PlayerId TicTacToeClient::StartGame()
{
  // Data we are sending to the server.
  Empty request;
  // request.set_name(user);

  // Container for the data we expect from the server.
  StartReply reply;

  // Context for the client. It could be used to convey extra information to
  // the server and/or tweak certain RPC behaviors.
  ClientContext context;

  // The actual RPC.
  Status status = stub_->StartGame(&context, request, &reply);

  // Act upon its status.
  if (status.ok())
  {
    if (reply.first_player() == tictactoe_if::Player::X)
    {
      return tictactoe::PlayerId::X;
    }
    else
      return tictactoe::PlayerId::O;
  }
  else
  {
    return tictactoe::PlayerId::None;
  }
}

bool TicTacToeClient::MakeMove(const tictactoe::Move &move)
{
  // Data we are sending to the server.
  tictactoe_if::Move request;
  request.set_row(move.row);
  request.set_col(move.col);

  // Container for the data we expect from the server.
  tictactoe_if::MoveReply reply;

  // Context for the client. It could be used to convey extra information to
  // the server and/or tweak certain RPC behaviors.
  ClientContext context;

  // The actual RPC.
  Status status = stub_->MakeMove(&context, request, &reply);

  // Act upon its status.
  if (status.ok())
  {
    return true;
  }
  else
  {
    std::cout << status.error_code() << ": " << status.error_message() << std::endl;
    return false;
  }
}
