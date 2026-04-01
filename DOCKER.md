# MiniRT with Docker Compose

Welcome to MiniRT Docker Documentation! Here we will see how to setup docker and then how the creation of the miniRT docker image works and how to properly run its container with docker compose.

## Setting up Docker

You can see the setup in the [Official Docker Documentation](https://docs.docker.com/engine/install/ubuntu/#installation-methods), or following up the next instructions:

1. **Setup Docker apt repository:**
	```bash
	# Add Docker's official GPG key:
	sudo apt update
	sudo apt install ca-certificates curl
	sudo install -m 0755 -d /etc/apt/keyrings
	sudo curl -fsSL https://download.docker.com/linux/ubuntu/gpg -o /etc/apt/keyrings/docker.asc
	sudo chmod a+r /etc/apt/keyrings/docker.asc

	# Add the repository to Apt sources:
	sudo tee /etc/apt/sources.list.d/docker.sources <<EOF
	Types: deb
	URIs: https://download.docker.com/linux/ubuntu
	Suites: $(. /etc/os-release && echo "${UBUNTU_CODENAME:-$VERSION_CODENAME}")
	Components: stable
	Architectures: $(dpkg --print-architecture)
	Signed-By: /etc/apt/keyrings/docker.asc
	EOF

	sudo apt update
	```

1. **Install Docker latest version:**

	```bash
	sudo apt install docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin
	```

1. **Check the Docker service status**

	```bash
	sudo systemctl status docker
	```
	**If is not running, run:**

	```bash
	sudo systemctl start docker
	```

## How to Create the MiniRT Docker Image

As you can see in the [Dockerfile](./Dockerfile), the image was created based on debian at version 12, it is visible in the first line of the file.

### How a Dockerfile Works and How it was use here?

A Dockerfile is very like a recipe showing all the steps to build the environment necessary to run a specific program. It is composed of directives followed by arguments.

**Here I will explain only the directives used in the miniRT image building process.**

```Dockerfile
# The FROM directive indicates which environment the image will be based from.
FROM environment

# The RUN directive indicates a command line that should be executed (it will be executed on the default shell avaliable).
RUN command1 && command2 || command3

# The WORKDIR directive is not just a `cd` command, actually, if the given directory does not exists, it is created and then there is a `cd` into it. (by default the WORKDIR is `/`).
WORKDIR /some/directory

# The ENV directive simply defines an environment variable
ENV key=value

# the COPY directive copies some content from the host environment to the image environment
COPY from to
```

Knowing this you can see that the building process of the miniRT image is basically:

1. Installing the C dependencies, the minilibx dependencies and the X11 dependencies.
1. Copying of all of miniRT content located on host, to the image's `/ecole42-miniRT` directory ***(could be any directory of any name)***.
1. Building of the mandatory and bonus versions through `make` commands, with the purpose of get the **miniRT executables**.
1. Extracting the **miniRT executables** to the `root` directory.
1. Defining the permissionning of execution of the **miniRT executables** as **enabled**.
1. Removing the image's `/ecole42-miniRT` directory and all it's content.

## How to Properly run a Docker Container with the MiniRT Image

Most of the configuration needed came from the X11 environment. A normal container run whould not require all of that.

### Obs. How is a pure docker docker run?

To see the difference between a pure docker run, and a docker compose run (current doc), see the branch [infra/docker](https://github.com/minishell-brunofer-ighannam/ecole42-miniRT/blob/infra/docker/DOCKER.md)

Before loocking to the command, lets understand the [docker-compose.yml](./docker-compose.yml) for this miniRT container:

```yml
# indicates which services are available
services:
  # indicates a service named minirt
  minirt:
    # indicates the container name (obs.: if the build directive was not provided it whould search on https://hub.docker.com for an image with this name and pulled it from there)
    image: minirt:1.0
    # indicates tha the image is to be built instead of pulling it from https://hub.docker.com. In this case it will search for a Dockerfile inthe given directory `.`
    build: .
    # indicates the container name tha can be used in docker to future access, edition, removal, networking config, etc.
    container_name: minirt
	# the environment variables should be placed here
    environment:
		# Declares an Environment Variable `DISPLAY=$DISPLAY`. The `$DISPLAY` variable is created by the `X11` and indicates the socket value that is to be used.
		# The objective here is that the container has the same `$DISPLAY` variable than the host
      - DISPLAY=${DISPLAY}
		# Declares an Environment Variable `XAUTHORITY=$X11AUTHORITY`. The `$X11AUTHORITY` var was created on Makefile and uses the `$XAUTHORITY` var internaly, which was created by `X11` and represents the path to `X11` authentication protocol.
		# The objective here is that the container has the same `$XAUTHORITY` variable than the host.
      - XAUTHORITY=${X11AUTHORITY}
    volumes:
		# Creates a Volume named `x11_environment` that takes the content of a path from the host and copy to `/tmp/.X11-unix` path of the container environment.
		# This is to give support to the `$DISPLAY` variable that will search the display value in this directory.
      - x11_environment:/tmp/.X11-unix
	  	# Creates a Volume that takes the content of `$X11AUTHORITY` path from the host and copy to `$X11AUTHORITY` path of the container environment.
		# The objective is to allow the connection between the container and the graphic server of `X11`. Without this, the container whould have no permission to establish connection, resulting in a `Core Dumped` error on a `mlx_new_window(args)` call.
      - ${X11AUTHORITY}:${X11AUTHORITY}
		# Creates a Volume named `scene` that takes the content of a path from host and copy to `/scene` path of the container environment.
		# The objective is to allow the container access the scene files, without this there whould be an error `No such file or directory`.
      - scene:/scene
		# Creates a Volume named `texture_map_color` that takes the content of a path from the host and copy to `/texture_map_color` path of the container environment.
		# The objective is to allow the container to access the texture_map_color files, without this the textures whould not load.
      - texture_map_color:/texture_map_color
		# Creates a Volume named `texture_map_normal` that takes the content of a path from the host and copy to `/texture_map_normal` path of the container environment.
		# The objective is to allow the container to access the texture_map_normal files, without this the normals whould not load.
      - texture_map_normal:/texture_map_normal

# indicates which volumes are available and wich is it's spacifications
volumes:
  # the x11_environment Volume represents the `/tmp/.X11-unix` path on host
  x11_environment:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: /tmp/.X11-unix
  # the scene Volume represents the `./scene` path on host
  scene:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: ./scene
  # the texture_map_color Volume represents the `./texture_map_color` path on host
  texture_map_color:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: ./texture_map_color
  # the texture_map_normal Volume represents the `./texture_map_normal` path on host
  texture_map_normal:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: ./texture_map_normal
```

So this is the command taken from [Makefile](./Makefile):

```Makefile
# Gets the X11 Auth protocol path from var $XAUTHORITY, or defines a default path if $XAUTHORITY is empty.
X11AUTHORITY:=$(if $(XAUTHORITY),$(XAUTHORITY),/tmp/.Xauthority)

...

# Docker Command Here
docker_mandatory: Dockerfile docker-compose.yml
	@export X11AUTHORITY=$(X11AUTHORITY) && docker compose run --rm minirt /miniRT /$(SCENE)
```

Now lets break down everything:

- **export X11AUTHORITY=$(X11AUTHORITY)** - exports the Environment Variable named X11AUTHORITY tha will be used on docker compose.
- **docker compose run** - Request docker to read the docker-compose.yml file on the current directory, and based on it build or pull an image, and after that use that image to run some command, which we will see in the next arguments.
- **minirt** - Request docker to run a command in a container named **minirt**.
- **/miniRT /$(SCENE)** - Requests docker to run this command on the given container (remember, those commands are been excuted on a Makefile)
