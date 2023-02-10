let time=window.prompt("Enter the number of parked hours: ");
function calc(time){
    let cost=2;
    if(time>3){
        cost=2+(time-3)*(0.5);
        if(cost>10){
            cost=10;
        }
    }
    return cost;
}
let cost=calc(time);
document.getElementById("a1").innerHTML=cost;
