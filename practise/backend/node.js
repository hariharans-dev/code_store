const express = require('express')
const path=require('path')
const app=express()

app.get('/',(req,res)=>{
    res.sendFile(path.join(__dirname,'../index.html'))
})

app.get('/form',(req,res)=>{
    console.log('this is welcome')
})

app.get('/form1',(req,res)=>{
    console.log('this is hello')
})

app.listen(8000,()=>{
    console.log('server is up')
})