
#include <iostream>

#include "lib/tictactoe_client.hpp"

int main(int argc, char **argv)
{

  // Instantiate the client. It requires a channel, out of which the
  // actual RPCs are created. This channel models a connection to an
  // endpoint (in this case, localhost at port 50052). We indicate
  // that the channel isn't authenticated (use of
  // InsecureCredentials()).
  TicTacToeClient client(
      grpc::CreateChannel("localhost:50052", grpc::InsecureChannelCredentials()));
  std::string user("Ivo");
  std::cout << "Sending: " << user << std::endl;
  std::string reply = client.EnterGame(user);
  std::cout << "Reply received: " << reply << std::endl;

  return 0;
}
