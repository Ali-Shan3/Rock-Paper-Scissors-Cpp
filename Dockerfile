# Base image with gcc
FROM gcc:12

# Set working directory inside container
WORKDIR /app

# Copy all project files into container
COPY . .

# Compile your main C++ file (replace main.cpp with your actual filename)
RUN g++ -o rock-paper-scissors main.cpp

# Run the compiled program
CMD ["./rock-paper-scissors"]
