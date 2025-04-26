FROM --platform=linux/amd64 ubuntu:22.04 as builder

# Prevent interactive prompts
ENV DEBIAN_FRONTEND=noninteractive

# Install build dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    ninja-build \
    cmake

# Set working directory
WORKDIR /work
