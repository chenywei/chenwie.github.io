//正方形
function Square(n,xx,zz){
  let x="";
  switch(xx){
    case 1:
      //实心
      for(var i=0;i <n;i++){
            for(var j=0;j<n;j++){
                x+=zz
            }
            x+='\n'
        }
        console.log(x)
        break;
     case 2:
       //空心
      for(var i=0;i<n;i++){
            for(var j=0;j<n;j++){
                if(i>0&&i<n-1&&j>0&&j<n-1){
                    x+='  '
                } else {
                    x+=zz
                }
            }
            x+='\n'
        }
        console.log(x)
        break
  }  
}
//三角形
function Triangle(n,xx,zz){
  let x="";
  let m=2*n;
  switch(xx){
    //实心
    case 1:
      for(var i=0;i<=n;i++){
    for(var j=0;j<=m;j++){
        if(j-i<=n&&j+i>=n||i==n){
            x+=zz
        } else{
            x+='  '
        }
    }
    x+='\n'
}
    console.log(x)
    break;
    //空心
    case 2:
      for(var i=0;i<=n;i++){
            for (var j =0;j<=m;j++){
                if(j-i==n||j+i==n||i==n){
                    x+=zz
                } else{
                    x+='  '
                }
            }
            x+='\n'
        }
        console.log(x)
        break;
  }
}
//菱形
function diamond(n,xx,zz){
  let x="";
  let m=2*n;
  switch(xx){
    //实心
    case 1:
      for(var i=-5;i<=n;i++){
      for (var j =0;j<=m;j++){
              if(j>=Math.abs(i)&&j<=m-Math.abs(i)){
                  x+=zz
              } else{
                  x+='  '
              }
          }
          x+='\n'
      }
    console.log(x)
    break;
    case 2:
    //空心
      for(var i=-5;i<=n;i++){
          for (var j =0;j<=m;j++){
            if(j==Math.abs(i)||j+Math.abs(i)==m){
                     x+=zz
            } else{
               x+='  '
           }
      }
    x+='\n'
}
console.log(x)
break;
  }
}
//梯形
function Trapezoid(n,xx,zz){
  let x="";
  let m=2*n;
  switch(xx){
    //实心
    case 1:
       for(var i=0;i<n;i++){
        for(var j=0;j<m;j++){
            if(j-i<=n&&j+i>=n&&i>1){
                x+=zz
            } else{
                x+='  '
            }
        }
        x+='\n'
    }
    console.log(x)
    break;
    //空心
    case 2:
      for(var i=0;i<=n;i++){
            for (var j =0;j<=m;j++){
                if((j-i==n||j+i==n||i==n)&&i>1||i==2&&(j<=5-i||j<=5+i)&&(j>=5-i||j>=5+i)){
                    x+=zz
                } else{
                    x+='  '
                }
            }
            x+='\n'
        }
        console.log(x)
        break;
  }
}
//回字
function hui(n,xx,zz){
  let x="";
  let m=parseInt(n/3);
  switch(xx){
    case 1:
      console.log("没这个玩意")
      break;
    case 2:
      for(var i=0;i<=n;i++){
        for (var j=0;j<=n;j++){
            if(i==0||i==n||j==0||j==n){
                x+=zz;
            } else if((i==n-m||i==m)&&(j<=n-m&&j>=m)){
                x+=zz;
            } else if((j==m||j==n-m)&&(i<=n-m&&i>=m)){
                x+=zz;
            }  else {
                x+='  ';
            }    
        }
        x+="\n"
    }
    console.log(x)
    break;
  }
}
function main(n,xx,cc,shape){
  var zz;
  switch(cc){
    case 1:
      zz=" *"
      break;
    case 2:
      zz=" #"
  }
  switch(shape){
    case 1:
      Square(n,xx,zz);
      break;
    case 2:
      Triangle(n,xx,zz);
      break;
    case 3:
      diamond(n,xx,zz);
      break;
    case 4:
      Trapezoid(n,xx,zz);
      break;
    case 5:
      hui(n,xx,zz);
      break;
  }
}
const readline = require('readline');
async function input(msg){
    return await new Promise((resolve,reject)=>{
        const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
        });
        rl.question(msg,(answer)=>{
            resolve(answer);
            rl.close();
        });
    })
}
(async()=>{
    var shape=await input("正方形按1，三角形按2，菱形按3，梯形按4,回字按5\n");
    var n =await input("请输入高度\n");
    var cc =await input("使用*按1，使用#按2\n");
    var xx =await input("实心按1，空心按2\n");
    main(Number(n),Number(xx),Number(cc),Number(shape))
})()
