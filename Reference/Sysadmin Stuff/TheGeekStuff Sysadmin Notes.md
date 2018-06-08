[Link](https://www.thegeekstuff.com/2010/12/50-unix-linux-sysadmin-tutorials/?utm_source=feedburner)

## 1 - dd

### Sync
[Source](https://www.safaribooksonline.com/library/view/linux-system-programming/0596009585/ch04s05.html)  
* Synchronous
	* Operation returns once complete
* Asynchronous
	* Operation returns once queued
* Synchronized
	* Operation returns once written to disk
* Non-synchronized
	* Operation returns once written to data buffer


### Blocks
A __block__ is a unit measuring the number of bytes that are read, written, or converted at one time.

[Tuning dd block size](http://blog.tdg5.com/tuning-dd-block-size/)  
[Eug-lug dd block size speed test](https://www.mail-archive.com/eug-lug@efn.org/msg12073.html)  
* Default block size is 512
* Above bs=512, copy speed is doubled, however larger block sizes will not result in proportionately greater speed increases
* Example:  
`dd if=/dev/foo of=/dev/foo bs=4k count=100M`

[Difference between blocks and sectors](http://www.alphaurax-computer.com/computer-tips/hard-drive-knowledge-blocks-vs-sectors)  
* On hard drives and folppies, each sector can hold 512 bytes of data
* A block is a group of sectors the OS can address
* A block might be a single or several sectors (2, 4, 8, 16)
	* The bigger the drive, the more sectors a block will hold

Difference between _size on disk_ and _bytes used_:
* Lots of little files may result in wasted space
* For example, the properties of a file might say `12K on disk` and `8320 bytes used`
	* Space on disk depends on block size
	* Always a multiple of block size

### The ext4 filesystem
[Source](https://opensource.com/article/17/5/introduction-ext4-filesystem)




## 2 - rsync
Usage: `rsync options source destination`
* `-a` for recursively, preserving timestamps, r/w permissions, etc.
* `-r` for recursively without the extra functionalities of `-a`
* `-v` verbose
* `-z` enable compression

__Example:__ `rsync -avz /root/temp/ sliu@192.168.0.24:/home/cyamo/temp`

## 3 - Three sysadmin rules
1. Regularly backup everything and validate
2. Master the CLI (and avoid UI if possible)
3. Be lazy and automate


## 4 - User and group disk quota
