#pragma once

#include <memory>
#include <string>
#include <grpc++/grpc++.h>

#include "protos/tictactoe.pb.h"
#include "protos/tictactoe.grpc.pb.h"

#include "lib/types.hpp"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using tictactoe_if::TicTacToe;

class TicTacToeClient
{
public:
  TicTacToeClient(std::shared_ptr<Channel> channel);
  // Assambles the client's payload, sends it and presents the
  // response back from the server.
  tictactoe::PlayerId StartGame();
  bool MakeMove(const tictactoe::Move &move);

private:
  std::unique_ptr<TicTacToe::Stub> stub_;
};
