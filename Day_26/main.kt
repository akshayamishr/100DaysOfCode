import kotlin.math.max
fun main()
{
    println("Namaste Sansar")
    var userName: String = "Akshaya"
    userName = "Akshaya Mishra"
    print("My name is $userName;")
    // var is used for the variables which could change in the upcoming code
    // val are like const there do not change
    // type inference -> we don't have to specify the data types
    val age = 19
    println(" I am $age years old")
    // data types
    // Int
    val maxIntegerValue: Int = Int.MAX_VALUE
    val minIntegerValue: Int = Int.MIN_VALUE
    println("Minimum value of Int is: $minIntegerValue")
    println("Maximum value of Int is: $maxIntegerValue")
    // Byte
    val maxByteValue: Byte = Byte.MAX_VALUE
    val minByteValue: Byte = Byte.MIN_VALUE
    println("Minimum value of Byte is: $minByteValue")
    println("Maximum value of Byte is: $maxByteValue")
    // long
    val maxLongValue: Long = Long.MAX_VALUE
    val minLongValue: Long = Long.MIN_VALUE
    println("Minimum value of Long is: $minLongValue")
    println("Maximum value of Long is: $maxLongValue")
    // float and double
    val myNumber  = 9.4f
    val mySecondNumber = 9.4567  // double
    println("Float: $myNumber  Double: $mySecondNumber")
    // char
    val myChar : Char = 'A'
    println("Char is : $myChar")

    // Operators
    var x = 5
    var y = 2
    println("Numbers are : $x and $y")
    println("+ operator : ${x + y}")
    println("- operator : ${x - y}")
    println("* operator : ${x * y}")
    println("/ operator : ${x / y}")
    println("% operator : ${x % y}")
    //
    println("x++ = ${x++} and ++x = ${++x}")
    println("y-- = ${y--} and --y = ${--y}")

}
