fun main()
{
    val arr = arrayOf(1,3,8,5,9,10,87,68,90)
    val ans = minMax(arr)
    println("Largest element in the array is : ${ans.first}")
    println("Smallest element in the array is : ${ans.second}")
}

fun minMax(arr:Array<Int>) : Pair<Int,Int>
{
    var min = Int.MAX_VALUE
    var max = Int.MIN_VALUE
    for(i in arr)

    {
        if(i >= max) max = i
        else if(i <= min) min = i
    }
    return Pair(min,max)
}