FROM ubuntu:bionic

WORKDIR /app
COPY . .
RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y build-essential cmake && \
    apt-get install -y python3.6 python3-pip

WORKDIR /app/web-gui
RUN python3.6 -m pip install pip --upgrade && \
    python3.6 -m pip install -r requirements.txt && \
    rm -rf .gitignore .travis.yml README.md requirements.txt startup.sh docker-pyinstaller*

EXPOSE 5000 1337 1338 1339
ENTRYPOINT python3.6 run.py
