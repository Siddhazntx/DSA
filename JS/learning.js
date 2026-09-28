const product = {
    "name" : "phone",
    "price" : 1000
}; //object

const result = {
    "product":"Ball",
    "InStock":23,
    "Price":300,
    "option":"Blue"
};

//Array
const prod = [
    {'name':'phone','price':23000},
    {'name':'ball','price':300}
];

// const {data,errors} = await supabase
//     .from("products")
//     .select("*");

const productss = ["pixel","iphone"];

const[first,second] = productss;

const item = {
    'name':'phone',
    'price':23000
};

const update_prod = {
    ...item,
    'price':343000
};

function add(a,b){
    return a+b;
}

function caldiscount(price,discount){
    return price-discount;
}

//Arrow function

const add = (a,b)=>{
    return a+b
};

const add = (a,b) => a+b;

//Callback

function processprod(product,callback){
    const result = product*2;
    callback(result);
}

processprod(product, result =>{
    console.log(result);
});//function inside a function calling another one


const products = [
    { id: 1, name: "iPhone", price: 70000 },
    { id: 2, name: "Pixel", price: 60000 },
    { id: 3, name: "Samsung", price: 50000 }
];

const names = products.map(product => product.name);
const id = products.map(product=>product.id);
const cheapitem = products.filter(product =>{
    product.price<1000;
});