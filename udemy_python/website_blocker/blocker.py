"""
Website blocker app
Hosts file on windows:
C:\Windows\System32\drivers\etc
Hosts file on mac:
/etc/hosts
"""

import os
import platform
import time
import datetime

if platform.platform().lower().find('windows') > -1:
    hosts_path = r"C:\Windows\System32\drivers\etc"
else:
    hosts_path = "/etc/hosts"
hosts_path = "hosts"
redirect = "127.0.0.1"
website_list = ["twitter.com", "tripadvisor.com"]
working_hours = (datetime.time(9), datetime.time(18))
blocking = True

def block_websites(add_block):
    # os.chmod(hosts_path, 0o777)
    if add_block:
        with open(hosts_path, 'a+') as f:
            if '# START' in f.read():
                return
            f.write('\n# START BLOCKING')
            for website in website_list:
                f.write('\n127.0.0.1       {}'.format(website))
                f.write('\n127.0.0.1       www.{}'.format(website))
            f.write('\n# END BLOCKING\n')
    else:
        with open(hosts_path, 'w+') as f:
            lines = []
            remove = False
            for line in f.readlines():
                if line.find('START BLOCKING') > -1:
                    remove = True
                if not remove:
                    lines.append(line)
                if line.find('END BLOCKING') > -1:
                    remove = False
            f.write(lines)

#while True:
if 1:
    time.sleep(5)
    now = datetime.datetime.now().time()
    if now > working_hours[0] and now < working_hours[1]:
        if not blocking:
            block_websites(True)
    else:
        if blocking:
            block_websites(False)

