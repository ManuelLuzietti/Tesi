FROM ubuntu:bionic

WORKDIR /app
COPY . .
RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y build-essential cmake && \
    apt-get install -y python3 python3-pip && \
    apt-get install -y git

WORKDIR /app/byob
RUN python3 -m pip install pip  --upgrade && \
    python3 setup.py && \
    python3 -m pip install colorama && \
    python3 -m pip install -r requirements.txt
 

EXPOSE 8080 8081 8082 8083
ENTRYPOINT ["python3", "server.py", "--port","8080","--debug"]
