<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h1>LOGIN</h1>
    <form action="" method="POST">
        <label for="username">USERNAME :</label>
        <input type="email" name="email"><br>
        <label for="password">PASSWORD :</label>
        <input type="password" name="password"><br>
        <input type="submit" name="login">
    </form>
    <?php
    if(isset($_POST['login'])){
        session_start();
        $email=$_POST['email'];
        $pass=$_POST['password'];

        $conn=mysqli_connect('localhost','root','','test1');

        if($conn)
        {
            $q="SELECT * FROM users WHERE email='$email' AND password='$pass'";
            $query=mysqli_query($conn,$q);
            if($query)
            {
                if(mysqli_num_rows($query)>0)
                {
                    $row=mysqli_fetch_assoc($query);
                    $_SESSION['name']=$row['name'];
                    header('location:welcome.php');
                }else{
                    echo "Cannot login";
                }
            }
            else
            {
                echo "no users found";
            }
        }
        else
        {
            echo "connection unsucessful";
        }


    }
    else{
        
    }
    ?>
</body>
</html>