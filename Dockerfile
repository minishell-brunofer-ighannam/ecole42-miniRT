FROM debian:12

RUN apt update && apt install -y build-essential gdb valgrind make \
	# install minilibx dependencies
	libx11-dev libxext-dev libbsd-dev \
	# install X11 environment
	libxrender-dev libxrandr-dev libxinerama-dev libxcursor-dev libxfixes-dev x11-utils

ENV DISPLAY=:0
ENV XAUTHORITY=:0

WORKDIR /ecole42-miniRT

COPY . .

RUN make BUILD=true
RUN make bonus BUILD=true

RUN mv miniRT /miniRT && mv miniRT_bonus /miniRT_bonus

RUN chmod +x /miniRT /miniRT_bonus

WORKDIR /

RUN rm -rf /ecole42-miniRT
