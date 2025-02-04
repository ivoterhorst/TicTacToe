#include <iostream>

#include "tictactoe_client.hpp"

using tictactoe::Empty;
using tictactoe::StartReply;

// Constructor with "initialization list"
TicTacToeClient::TicTacToeClient(std::shared_ptr<Channel> channel)
    : stub_(TicTacToe::NewStub(channel)) {}

std::string TicTacToeClient::StartGame()
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
    if (reply.first_player() == tictactoe::Player::X)
    {
      return "Player X starts";
    }
    else
      return "Player O starts";
  }
  else
  {
    return "RPC failed";
  }
}
