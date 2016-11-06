# sshguard-rhel7

I created this because I was tired of how easy it was to install sshguard on ubuntu
(it's in the repos and starts on install without mucking around with iptables) but it's
not to be found for rhel, centos, or fedora.

This was created from compiling sshguard 1.7.1 from source from sshguard.sourceforge.net
and I used some of the files in the ubuntu version 1.6.0 to make it auto-start and configure
iptables.

To install:
```
rpm -i https://github.com/bryceml/sshguard-rhel7/raw/master/RPMS/x86_64/sshguard-1.7.1-1.el7.x86_64.rpm
```
