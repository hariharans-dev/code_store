var app=angular.module("myapp",[]);
app.controller("myctrl",function($scope){
    $scope.arr=[1,2,3,4,5];
    $scope.name=[
        {
            text:"welcome",
            age:18
        },
        {
            text:" to",
            age:19
        },
        {
            text:" vit",
            age:20
        }
    ]
});
app.directive("he", function() {
    return {
        template : "<h1>Made by a directive!</h1>"
    };
});