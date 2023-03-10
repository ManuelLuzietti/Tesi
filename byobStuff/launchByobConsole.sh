containers=`docker ps -a | grep -A 1 byob | cut -b -12`
for x in $containers; do docker stop $x && docker rm $x ; done
docker run -p 8080:8080 -p 8081:8081 -p 8082:8082 -p 8083:8083 -v ./byob-console:/app --name byob-console  -ti  byobconsole --debug

