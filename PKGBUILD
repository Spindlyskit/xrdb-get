# WARN: This is a local PKGBUILD for arch linux systems
# It will not work if not provided in the root of this repo

author=Spindlyskit
pkgname=xrdb-get-git
pkgver=1.0
pkgrel=1
pkgdesc='A simple utility to read values from xresources from the command line'
arch=('x86_64')
license=('MIT')
provides=('xrdb-get')

build() {
	cd ..
	make
}

package() {
	cd ..
	make PREFIX=/usr DESTDIR="$pkgdir" install
	install -m644 -D LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
