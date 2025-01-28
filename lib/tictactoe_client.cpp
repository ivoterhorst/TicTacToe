#include <iostream>

#include "tictactoe_client.hpp"

// Constructor with "initialization list"
TicTacToeClient::TicTacToeClient(std::shared_ptr<Channel> channel)
    : stub_(TicTacToe::NewStub(channel)) {}

std::string TicTacToeClient::EnterGame(const std::string &user)
{
  // Data we are sending to the server.
  EnterRequest request;
  request.set_name(user);

  // Container for the data we expect from the server.
  EnterReply reply;

  // Context for the client. It could be used to convey extra information to
  // the server and/or tweak certain RPC behaviors.
  ClientContext context;

  // The actual RPC.
  Status status = stub_->EnterGame(&context, request, &reply);

  // Act upon its status.
  if (status.ok())
  {
    return reply.message();
  }
  else
  {
    return "RPC failed";
  }
}
