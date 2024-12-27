import os

class BankAcc:
    acc_no = 121000
    def __init__(self,name, acc_type, balance = 0.0):
        BankAcc.acc_no += 1
        self.acc_no = BankAcc.acc_no
        self.name = name
        self.acc_type = acc_type
        self.balance = balance
    
    def withdraw(self):
        amount = float(input("Enter the amount to withdraw: "))
        if amount <= user.balance:
            user.balance -= amount
            print(f"{amount} has been withdrawn from your account")
        else:
            print("Insufficient balance")
    
    def deposit(self):
        amount = float(input("Enter the amount to deposit: "))
        user.balance += amount
        print(f"{amount} has been added to your account")

    def __str__(self):
        return f"Name: {self.name} \nAccount number: {self.acc_no}\nAccount Type: {self.acc_type}\nBalance: {self.balance}"

if __name__ == "__main__":
    members = dict()
    while(True):
        os.system('cls')
        print("Welcome to Maal Bank")
        print("1.Create Account")
        print("2.Login")
        print("3.Check members")
        print("4.Exit")
        ch = int(input("Enter your choice: "))
        match(ch):
            case 1:           # creating acc
                os.system('cls')
                name = input("\nEnter your name: ").lower()
                acc_type = input("\nAccount type(savings / current): ").lower()
                balance = float(input("\nEnter the initial deposit to your account: "))
                user = BankAcc(name, acc_type, balance)
                members[user.name] = user
                print("Your account has been created: \n")
                print(user)
                input()

            case 2:
                name = input("Enter your name: ").lower()
                if name in members:
                    user = members[name]
                    while(True):
                        os.system('cls')
                        print("1.Withdraw")
                        print("2.Deposit")
                        print("3.Check balance")
                        print("4.Logout")
                        choice = int(input("Enter your choice: "))
                        match(choice):
                            case 1:
                                user.withdraw()
                            case 2:
                                user.deposit()
                            case 3:
                                print(user)
                            case 4:
                                break
                            case _:
                                print("Invalid Choice")
                        input()
                else:
                    print("user not found")

            case 3:
                if members:
                    print("The members are: ")
                    for member in members.keys():
                        print(member, end=", ")
                else:
                    print("There are no members to display")
                input()

            case 4:
                break

            case _:
                print("Invalid Choice")
                input()