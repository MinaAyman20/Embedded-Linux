#!/bin/bash 


username="MinaA."
groupname="Khalil"

if grep -q "^$username:" /etc/passwd; then
echo "User '$username' already exists"
else
sudo useradd "$username"
echo "user '$username' created "
fi

if grep -q "^$groupname:" /etc/group; then
echo "User '$groupname' already exists."
else
sudo groupadd "$groupname"
echo "group '$groupname' created "
fi

sudo usermod -aG "$groupname" "$username"

echo "User information"
grep "^$username:" /etc/passwd 

echo "Group information"
grep "^$groupname:" /etc/group






