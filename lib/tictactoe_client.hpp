#pragma once

#include <memory>
#include <string>
#include <grpc++/grpc++.h>

#include "protos/tictactoe.pb.h"
#include "protos/tictactoe.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using tictactoe::EnterReply;
using tictactoe::EnterRequest;
using tictactoe::TicTacToe;

class TicTacToeClient
{
public:
  TicTacToeClient(std::shared_ptr<Channel> channel);
  // Assambles the client's payload, sends it and presents the
  // response back from the server.
  std::string EnterGame(const std::string &user);

private:
  std::unique_ptr<TicTacToe::Stub> stub_;
};
