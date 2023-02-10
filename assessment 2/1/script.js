let total=0,n;
n=window.prompt("Enter the number of customers: ");
document.write("Number of customers is "+n+"<br>");
let i=1;
while(i<=n){
    let time=window.prompt("Enter the number of parked hours: ");
    total+=calculate(time,i);
    i++;
}
document.write("The total parking cost of customers is "+total+"<br>");
function calculate(time,count){
    let cost=2;
    if(time>3){
        cost=2+(time-3)*(0.5);
        if(cost>10){
            cost=10;
        }
    }
    document.write("<h1>parking cost of customer </h1>"+count+"<h1>whose time is </h1>"+time+"<h1> hours and $ </h1>"+cost+"<br>");
    return cost;
}


