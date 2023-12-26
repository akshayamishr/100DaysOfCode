fun main()
{
    val arr = arrayOf("ABC","XYZ",'D','W',1,9,2,8)
    println("Size : ${arr.size}")
    println("Integers in arr : ")
    for(i in arr)
    {
        if(i is Int) print("$i ")
    }
}