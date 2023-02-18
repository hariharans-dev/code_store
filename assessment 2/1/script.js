let n=prompt("Enter the number of customers: ");
let total=0,i=1;
if(n==0){
    document.write("<h1>There is no customers to park !!</h1><br>");
}
else{
    while(i<=n){
        let h=prompt("Enter the number of parking hours: ");
        let price=2,per=0.5;
        if(!h<=3){
            if(h>=24){
                price=10;
            }
            else{
                price=price+per*(h-3);
            }
        }
        total+=price;
        document.write("<h1>The parking hourse is "+h+" hours and the charge is "+price+"</h1><br>")
        i++;
    }
}
document.write("<h1>The total revenue of the parking agency is "+total+"</h1><br>")