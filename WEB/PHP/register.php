<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="" method="POST">
        <h2>Registration form</h2>
        <label for="name">Name :</label>
        <input type="text" name="name"><br>
        <label for="email">Email :</label>
        <input type="email" name="email"><br>
        <label for="phone">Phone no :</label>
        <input type="number" name="phone"><br>
        <label for="password">Password :</label>
        <input type="password" name="password"><br>
        <label for="repassword">Repassword :</label>
        <input type="password" name="repassword"><br>
        <input type="submit" name="Register"><br>
    </form>
        <h3>If already registered, <a href="login.php">login here</a></h3>
        <?php
        if(isset($_POST['Register']))
        {
            $name=$_POST['name'];
            $email=$_POST['email'];
            $phone_number=$_POST['phone'];
            $password=$_POST['password'];
            $repassword=$_POST['repassword'];

            if($password!=$repassword)
            {
                echo "passwords do not match!";
            }
            else
            {
                $conn=mysqli_connect('localhost','root','','test1');
            
                if(!$conn)
                {
                    echo "cannot connect";
                }
                echo "Connection success";
                $q="INSERT INTO users(name,email,password,phone_number)VALUES('$name','$email','$password','$phone_number')";
                $query=mysqli_query($conn,$q);
                if($query){
                    echo "<h2>Registered!</h2>";
                }
                else{
                    echo "<h2>Cannot register!</h2>";
                }
                mysqli_close($conn);

            }
        }
        ?>
</body>
</html>