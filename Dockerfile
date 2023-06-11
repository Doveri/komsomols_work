FROM kusharami/qt5-alpine-dev:latest

WORKDIR /server/server
COPY . .

RUN qmake echoServer_351.pro
RUN make

ENTRYPOINT ["./echoServer_351"]