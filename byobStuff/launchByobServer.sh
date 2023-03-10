containers=`docker ps -a | grep -A 1 byob | cut -b -12`
for x in $containers; do docker stop $x && docker rm $x ; done
docker run --name byob-web -it  -p 5000:5000 -p 1337:1337 -p 1338:1338 -p 1339:1339 -v ./byob:/app   byobserver 
