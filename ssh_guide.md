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
