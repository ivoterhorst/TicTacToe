#!/bin/zsh

# Generate C++ code from proto file
# Later to be replaced by Bazel genrule

# Generate from proto file
protoc -I . --cpp_out=../protogen tictactoe.proto

# Generate for grpc
protoc -I . --grpc_out=../protogen --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` tictactoe.proto
