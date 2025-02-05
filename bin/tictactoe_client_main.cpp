
#include <iostream>

#include "lib/tictactoe_client.hpp"
#include "lib/types.hpp"

int main(int argc, char **argv)
{

  // Instantiate the client. It requires a channel, out of which the
  // actual RPCs are created. This channel models a connection to an
  // endpoint (in this case, localhost at port 50052). We indicate
  // that the channel isn't authenticated (use of
  // InsecureCredentials()).
  TicTacToeClient client(
      grpc::CreateChannel("localhost:50052", grpc::InsecureChannelCredentials()));
  // std::string user("Ivo");
  // std::cout << "Sending: " << user << std::endl;
  tictactoe::PlayerId startingPlayer = client.StartGame();
  std::cout << "Player who starts: " << startingPlayer << std::endl;

  bool moveMade = client.MakeMove({1, 1});
  if (moveMade)
  {
    std::cout << "Move made" << std::endl;
  }
  else
  {
    std::cout << "Move not made" << std::endl;
  }

  return 0;
}
