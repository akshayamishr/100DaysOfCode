fun main(){
    hello("ASH")
    println("${max(10, 11)} is greater than ${min(10, 11)}")
    println(message = "Largest value in set {10,11,12} is ${max(10,11,12)}")
    println("${sum(4,5,23,657,75,36)}")
}

fun hello(name:String="User"){  // here User is default value
    println("Hello ${name}, how are you ?")
}

fun max(x:Int, y:Int):Int
{
//    if(x>y) return x
//    else return y
    val maxVal = if(x > y) x else y
    return maxVal
}

fun min(x:Int,y:Int) = if(x<y) x else y

// recursion and function overloading(changing number of arguments)
fun max(x:Int,y:Int,z:Int) = if(max(x,y) < z) z else max(x,y)

// Using vararg, we can pass comma-separated variable number of arguments to a function
fun sum(vararg numbers:Int):Int{
    var result = 0
    for(i in numbers)
        result += i
    return result
}