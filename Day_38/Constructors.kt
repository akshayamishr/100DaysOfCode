fun main()
{
    val user1 = User("War Lord",3005)
    println("User_Name : ${user1.name}    User_id : ${user1.id}")

    val user2 = User("Dashing")
    println("User_Name : ${user2.name}    User_id : ${user2.id}")

    val user3 = User(1001)
    println("User_Name : ${user3.name}    User_id : ${user3.id}")

    val user4 = User(name = "Prince Kymar", id = 1110)
    println("User_Name : ${user4.name}    User_id : ${user4.id}")
}

// class having multiple secondary constructor
class User (var name:String,var id:Int)
{
    // Secondary constructor calling primary constructor
    constructor(name : String) : this(name,1002){
        println("2nd")
    }

    // Secondary constructor calling another secondary constructor
    constructor(id:Int) : this("Akshaya",id){
        println("3rd")
    }
}
