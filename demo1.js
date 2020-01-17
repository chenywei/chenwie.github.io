const net = require('net');
const fs = require('fs');
const server = net.createServer();
server.on("connection", (client) => {
    console.log("来客了,接客了");
    client.on("data", (data) => {
        console.log(data.toString());
        data=data.toString();
        var index = data.indexOf('\n');
        var str = data.substring(0, index).trim();
        const [Method, Route, Edition] = data.split(' ');
        // console.log(Edition)
        if(Method=="GET"&&Route=="/"){
            client.write('HTTP/1.1 200 OK \n')
            client.write('Content-Type: text/html;charset=UTF-8\n\n')
            client.write('<h1>welcome</h1><a href="/admin">进入管理后台</a>\n')
            client.end()
        }
        if(Method=="GET"&&Route=="/admin"){
            var ar=data.trim().split('\n');
            var st=ar[(ar.length)-1];
            console.log(st)
            var last= st.split("=");
            console.log(last[1])
                if(fs.existsSync('./'+last[1]+'.txt')){
                    fs.readFile('./'+last[1]+'.txt',(err,data)=>{
                        client.write('HTTP/1.1 200 OK \n');
                        client.write('Content-Type: text/html;charset=UTF-8\n\n');
                        client.write(`${data}已登入`);
                        client.end(); 
                    })
            } else {
                client.write('HTTP/1.1 302 OK \n');
                client.write('Content-Type: text/html;charset=UTF-8\n');
                client.write('Location:http://localhost:8001/login\n\n');
                client.end();
            }
        }
        if(Method=="GET"&&Route=="/login"){
            client.write('HTTP/1.1 200 OK\n');
            client.write('Content-Type: text/html;charset=UTF-8\n\n');
            client.write('<form method="post" action="http://localhost:8001/login"><br>');
            client.write('<span>账号</span><input type="text" name="username" id=""><br>');
            client.write('密码<input type="password" name="pwd" id=""><br>');
            client.write('<input type="submit" value="登录">');
            client.write('</form>');
            client.end();
        }
        if(Method=="POST"&&Route=="/login"){
            var mm=(Math.ceil(Math.random()*1000)).toString(16);
            var str1=data.trim();
            var str2=str1.lastIndexOf('\n');
            var str3=str1.substr(str2);
            var bb=str3.split("&");
            if ((bb[0].split('=')[1]== 'admin')&&(bb[1].split("=")[1]=='123456')) {
                console.log('1111');
                fs.writeFile(`${mm}.txt`,bb[0].split('=')[1],()=>{
                    client.write('HTTP/1.1 302 OK \n')
                    client.write(`Set-Cookie: SESSID=${mm}\n`)
                    client.write('Content-Type: text/html charset = utf-8\n')
                    client.write("Location:http://localhost:8001\n\n")
                    client.end()
                })
            }
        }
    })
})
server.listen(8001, () => {
    console.log("怡红院开张了");
})