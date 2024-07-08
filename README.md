# CTF Note

## Description  
I will store some pwn writeups here for reference

## Some good references

[nobodyisnobody](https://github.com/nobodyisnobody/): Various docs with huge amount of writeups  
[welchbj](https://github.com/welchbj/ctf/blob/master/docs/binary-exploitation.md): Some interesting notes and techniques

## Challenge Index

<details>
<summary><h3>Heap challenges</h3></summary>
<p>

</p>
</details>

<details>
<summary><h3>Shellcode</h3></summary>
<p>
  
***Amateurs CTF 2024*** --> [baby-sandbox](https://hyggehalcyon.gitbook.io/page/ctfs/2024/amateursctf)  
> Shellcode using `sysenter` to escape sandbox where syscall are forbidden
> 
> Using register `xmm` to deal with deleted register

</p>
</details>

<details>
<summary><h3>Different architecture</h3></summary>
<p>

***DownUnder CTF 2024*** --> [pac-shell](https://github.com/DownUnderCTF/Challenges_2024_Public/tree/main/pwn/pac-shell)
> An arm64-bin challenge, which allow us to read, write arbitrary address
> 
> Use arm-gadget to invoke call to `system(/bin/sh)`

</p>
</details>
