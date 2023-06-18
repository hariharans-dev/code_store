const express=require('express')
const mongoose=require('mongoose')
app=express()

var userSchema=new mongoose.Schema({
    _id:mongoose.ObjectId,
    username:{type:String, required:true, unique:true},
    password:{type:String, required:true},
},{collection:'users'})

var user=mongoose.model("user",userSchema)

app.get('/',(req,res)=>{
    res.sendFile(__dirname + "/welcome.html")
})
app.get('/signuppage',(req,res)=>{
    res.sendFile(__dirname+"/signup.html")
})
app.get('/loginpage',(req,res)=>{
    res.sendFile(__dirname+'/login.html')
})


app.get('/signup',(req,res)=>{

    var obj
    obj=req.query

    mongoose.connect('mongodb://127.0.0.1:27017/mydatabase',{useNewUrlParser: true, useUnifiedTopology: true});
    const db=mongoose.connection;
    db.on('error',(err)=>{throw err})
    db.once('open',()=>{
        console.log('db connected')
    })
    
    user.create({
        _id:new mongoose.Types.ObjectId(),
        username: obj['username'],
        password: obj['password']
    })
    .then(()=>{res.send('new user is created')})
    .catch(err=>{res.send('User name already found')})
})

app.get('/login',(req,res)=>{

    var obj
    obj=req.query

    mongoose.connect('mongodb://127.0.0.1:27017/mydatabase',{useNewUrlParser: true, useUnifiedTopology: true});
    const db=mongoose.connection;
    db.on('error',(err)=>{throw err})
    db.once('open',()=>{
        console.log('db connected')
    })

    var password

    user.find({username:obj['username']},{_id:0,password:1})
    .then((result)=>{
        password=result[0]['password']
        console.log(password+" "+obj['password'])
    })
    .catch(err=>{console.log('error in finding')})

    password=String(password)
    obj['password']=obj['password']+'\n'
    console.log(password.length+" "+obj['password'].length)
    
    // if(password==obj['password']){
    //     console.log('pass')
    // }
    // else console.log('fail')

})

app.listen(8000,(req,res)=>{
    console.log('8000 is up')
})









