FROM gcc:12

WORKDIR /app

COPY . .

RUN g++ -o rock_paper_scissors main.cpp

CMD ["./rock_paper_scissors"]
