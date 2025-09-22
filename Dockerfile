# Base image with g++
FROM gcc:12

# Set working directory
WORKDIR /app

# Copy all source code into container
COPY . .

# Compile the C++ code
RUN g++ -o rock_paper_scissors main.cpp

# Run the compiled program
CMD ["./rock_paper_scissors"]
