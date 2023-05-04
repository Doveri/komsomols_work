FROM kusharami/qt5-alpine-dev:latest

WORKDIR /server/server/
COPY . .

RUN qmake echoServer.pro
RUN make

ENTRYPOINT ["./echoServer"]