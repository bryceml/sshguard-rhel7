Name:           sshguard
Version:        1.7.1
Release:        1.el7
Summary:        Protects from brute force attacks against ssh
Group:          System Environment/Daemons
License:        ISC
URL:            http://www.sshguard.net
Source0:        https://sourceforge.net/projects/sshguard/files/sshguard/1.7.1/sshguard-1.7.1.tar.gz/download

BuildRequires: gcc make systemd

%description
 Protects from brute force attacks against ssh
 Protects networked hosts from the today's widespread
 brute force attacks against ssh servers. It detects such attacks
 and blocks the author's address with a firewall rule.

%prep
%setup -q


%build
%configure --with-firewall=iptables
make %{?_smp_mflags}


%install
rm -rf $RPM_BUILD_ROOT
%make_install
mkdir -p ${RPM_BUILD_ROOT}/etc/sshguard
mkdir -p ${RPM_BUILD_ROOT}/etc/sysconfig
mkdir -p ${RPM_BUILD_ROOT}/usr/lib/sshguard
mkdir -p ${RPM_BUILD_ROOT}/usr/lib/systemd/system-preset
mkdir -p ${RPM_BUILD_ROOT}/usr/share/doc/sshguard/examples
mkdir -p ${RPM_BUILD_ROOT}/lib/systemd/system
cp -a ${RPM_BUILD_ROOT}/../../SOURCES/etc/sshguard/whitelist ${RPM_BUILD_ROOT}/etc/sshguard/whitelist
cp -a ${RPM_BUILD_ROOT}/../../SOURCES/etc/sysconfig/sshguard ${RPM_BUILD_ROOT}/etc/sysconfig/sshguard
cp -a ${RPM_BUILD_ROOT}/../../SOURCES/usr/lib/sshguard/firewall ${RPM_BUILD_ROOT}/usr/lib/sshguard/firewall
cp -a ${RPM_BUILD_ROOT}/../../SOURCES/usr/lib/systemd/system-preset/00-sshguard.preset ${RPM_BUILD_ROOT}/usr/lib/systemd/system-preset/00-sshguard.preset
cp -a ${RPM_BUILD_ROOT}/../../SOURCES/usr/share/doc/sshguard/examples/whitelistfile.example ${RPM_BUILD_ROOT}/usr/share/doc/sshguard/examples/whitelistfile.example
cp -a ${RPM_BUILD_ROOT}/../../SOURCES/usr/share/doc/sshguard/copyright ${RPM_BUILD_ROOT}/usr/share/doc/sshguard/copyright
cp -a ${RPM_BUILD_ROOT}/../../SOURCES/lib/systemd/system/sshguard.service ${RPM_BUILD_ROOT}/lib/systemd/system/sshguard.service

%files
%doc

/etc/sshguard/whitelist
/etc/sysconfig/sshguard
/usr/lib/sshguard/firewall
/usr/lib/systemd/system-preset/00-sshguard.preset
/lib/systemd/system/sshguard.service
/usr/libexec/sshg-fw
/usr/libexec/sshg-logtail
/usr/libexec/sshg-parser
/usr/sbin/sshguard
/usr/share/doc/sshguard/examples/whitelistfile.example
/usr/share/doc/sshguard/copyright
/usr/share/man/man8/sshguard.8.gz

%post
%systemd_post sshguard.service
if [ $1 -eq 1 ] ; then
	# Initial installation
	systemctl start sshguard.service >/dev/null 2>&1 || :
fi

%preun
%systemd_preun sshguard.service

%postun
%systemd_postun_with_restart sshguard.service

%changelog
* Sat Nov 05 2016 Bryce Larson <brycelarsn@gmail.com>
- Initial build using version 1.7.1 from sourceforge.net as well as systemd
  and environment files from the ubuntu package sshguard_1.6.0-1_amd64.deb
