## ssh相关笔记

### 查看是否有ssh

1. cd ~/.ssh
2. ls -la
> 如果有`id_rsa.pub`、`id_rsa`则无需创建 

### 创建ssh

1. ssh-keygen -t rsa -b 2048 -C "your email"
> 一直回车即可
2. cat id_rsa.pub
> ssh-rsa ... yourEmail
3. 把`rsa.pub`内容复制到`github`、`gitlab`
4. 以`github`为例，执行：ssh -T git@github.com，成功会有以下提示：
> Hi xx! You've successfully authenticated, but GitHub does not provide shell access.

### 其他

1. 把ssh添加到souceTree：ssh-add ~/.ssh/id_rsa
2. 把ssh添加到keyChain：ssh-add -K ~/.ssh/id_rsa
3. 在`~/.ssh`目录下，创建config文件：touch config
4. 打开`config`，复制以下内容进去后，保存，关闭：
````
Host *
   UseKeychain yes
   AddKeysToAgent yes
   IdentityFile ~/.ssh/id_rsa
   IdentityFile ~/.ssh/github_rsa
````

-----BEGIN OPENSSH PRIVATE KEY-----
b3BlbnNzaC1rZXktdjEAAAAABG5vbmUAAAAEbm9uZQAAAAAAAAABAAABFwAAAAdzc2gtcn
NhAAAAAwEAAQAAAQEAtA/X1v7RRcUlwg2Y9MqEkpEcxtmSQjadP/b3Tm1FMWke3HzzECtM
i6bh9kOJkl/vQBp89byNihtO4IEgEqxlYaF8drsc27zmmndrS3brOwEkoNqZQBYkQbCrod
T2xNQ3xf9j4TJx8HEWE7D2PCBeUBEQQ/HdgzyX/rQO6U4jjJv+A/2JXOXvmfTKuakmmD3z
HfMB6MDnEeDWuKjPtankRx53EwnDWNvfm7QydGrKy8gt8klpZMfTri+2b21OhnpHch0P/U
3LjhNtXPdB7A0xVQzVLV2y/v0AznsnmIm+VanbwOnpi4Wg0i6fMsw/x6vySWNke3lx+XOd
ejaGqZiIqwAAA8glrJldJayZXQAAAAdzc2gtcnNhAAABAQC0D9fW/tFFxSXCDZj0yoSSkR
zG2ZJCNp0/9vdObUUxaR7cfPMQK0yLpuH2Q4mSX+9AGnz1vI2KG07ggSASrGVhoXx2uxzb
vOaad2tLdus7ASSg2plAFiRBsKuh1PbE1DfF/2PhMnHwcRYTsPY8IF5QERBD8d2DPJf+tA
7pTiOMm/4D/Ylc5e+Z9Mq5qSaYPfMd8wHowOcR4Na4qM+1qeRHHncTCcNY29+btDJ0asrL
yC3ySWlkx9OuL7ZvbU6GekdyHQ/9TcuOE21c90HsDTFVDNUtXbL+/QDOeyeYib5VqdvA6e
mLhaDSLp8yzD/Hq/JJY2R7eXH5c516NoapmIirAAAAAwEAAQAAAQAimVy/Gi26O1y7AgPf
Hb8Frs6ZwxrgkD/9F4aD0mlWSj283mGSPM+zkfifanDX6Ik/hxd13KpR3Fd2ujkgfXHppa
8V3XR5IL4q9kFuucYPi3OvWPHTp62F1d3U9egJAEJLUHyvvBK6wfAdDobyHMIinnTCqYoH
+q+2KIEpAXPBQ7GbRwFDNgvcLhCZypAtxkpFHsGnoJGWDs7v4Il63po/89aOoPkF19mAGC
xM3ivvTi03xo+apx1pe7UoWnCF1aB+ysd0ASLX+ap/Vgr78wdJOtxBRR/qZ7/blaG3Q/Fq
Uc/5+cXWDF7PuxIK6+eqdxhIYq8zieXb40b5mTYLFym5AAAAgGq12T7xkExVMezyZjmJWL
PHGoAJVrvPCk3Uj1BQmB3bkWIToAiuLnKWdvzo1kfPYVWCwZ+u/JWb69DY1nN4YOKwQIqC
mCEKYE2zyNFkKHuKPpDtpdfb/Ta5aYJMa7QTyoIiIq/w16P8aoNY+IBTW7HNXM7nNuEA4u
CBRZRPC3ttAAAAgQDhVPjIEe9EHhVzYvFxPuIQ/dUw0Z0rcr+G0ChE9Wi/tobOsDEiUIbK
gnjBl6sVvsV7s4v0vTLbD9Gk2n+01sb01wRct6D81YdydwAz3cySbt5eCbr44UIhq/xWyh
3yPuZn73rYDquvsWyuIRPrgfqlesXi2ELLso3VpMDCVXwlxQAAAIEAzJGR8pXuAiQIjVCD
lgkxb5rxOFUTpgUM7ClSJP9QBWO5neMRuCE3o6+CTIN+/Ad1YWYKP/+xRHkvCQWoxQq/+x
UAoETpL96nITKX7h6OSsYEuHkhc+PMwW16ayTye1FD18IxQJ0HDeQeizO19YhgMYQhoaFm
9n+h4qZlKmSiS68AAAAQNDQ1MDE0Nzg5QHFxLmNvbQECAw==
-----END OPENSSH PRIVATE KEY-----



