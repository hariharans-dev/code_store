function clock(){
    const d=new Date();
    let h=d.getHours();
    let m=d.getMinutes();
    let s=d.getSeconds();
    m=checkTime(m);
    s=checkTime(s);
    document.getElementById("a2").innerHTML=h+":"+m+":"+s;
    setTimeout(clock,100);
}
function checkTime(i){
    if(i<10){i="0"+i;}
    return i;
}
let index=0;
