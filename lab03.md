---
layout: Slate
title: 推荐软件 Sublime Text 3
---

## [](header-1) 功能介绍

*   支持市面上流行的所有语言 :
    c、c++、java、python等等

![](https://github.com/MuaJacky/swi-homework/raw/gh-pages/Sublime/Code_Support.jpg)

*   追求极致速度，软件秒开

*   强大的插件系统，插件用的你眼花缭乱

## [](header-2) 插件功能

*   安装插件包的两种方法:
    - 直接安装:直接下载插件包然后解压缩到Packages目录   
    (找不到可以根据步骤:Preferences->Browse Packages)

    - Package Control安装:  

    按Ctrl + ` 调出控制台console,粘贴以下代码z至底部命令行并回车:  



             import urllib.request,os,hashlib; h = '6f4c264a24d933ce70df5dedcf1dcaee' + 'ebe013ee18cced0ef93d5f746d80ef60'; pf = 'Package Control.sublime-package'; ipp = sublime.installed_packages_path(); urllib.request.install_opener( urllib.request.build_opener( urllib.request.ProxyHandler()) ); by = urllib.request.urlopen( 'http://packagecontrol.io/' + pf.replace(' ', '%20')).read(); dh = hashlib.sha256(by).hexdigest(); print('Error validating download (got %s instead of %s), please try manual install' % (dh, h)) if dh != h else open(os.path.join( ipp, pf), 'wb' ).write(by)    


    ![](https://github.com/MuaJacky/swi-homework/raw/gh-pages/Sublime/Console.jpg) 


    然后重启Sublime Text 3,然后在Preferences -> package settings中看到package control,即为安装成功.此时按下Ctrl+Shift+P调出命令面板输入install packages并回车即可搜索网络中的插件包并进行安装.   

![](https://github.com/MuaJacky/swi-homework/raw/gh-pages/Sublime/install_packages.jpg)

    ps:安装进度条会显示在左下角.

# [](header-3) 插件推荐

*   MarkDown Editing

    -   对Sublime支持的Markdown文件的格式进行适当高亮以及其他的功能,让sublime显示markdown文本的能力大大提升.

*   SideBarFolders

    -   管理打开的文件所在的目录，以及打开的一些文件夹，利于集中的工程中管理自己的代码文件.

![](https://github.com/MuaJacky/swi-homework/raw/gh-pages/Sublime/SideBar.jpg)

*   SideBarEnhancements

    -   给左侧Folders栏增加极多功能
    -   并且让sublime具备实时预览页面的功能，只需要设置几个快捷键!

*   ConvetToUTF8

    -   将文件的编码转成utf-8

*   jsFormat

    -   快速格式化代码成js风格,**强迫症必备**

*   。。。

# [](header-3) 定义属于自己的快捷键

*   熟悉系统快捷键

    Preferences ->Key Bindings - Default

![](https://github.com/MuaJacky/swi-homework/raw/gh-pages/Sublime/KeyBindings.jpg)

*   自己设置快捷键

    Preferences ->Key Bindings - User

# [](header-4) 快捷键示例

*   Ctrl + Shift + ⬆/⬇

![](https://github.com/MuaJacky/swi-homework/raw/gh-pages/Sublime/move_line.gif)

*   Alt + F3

![](https://github.com/MuaJacky/swi-homework/raw/gh-pages/Sublime/Alt+F3.gif)

之后就可以尽情享用你们的代码之旅拉！