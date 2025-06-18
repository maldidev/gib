#!/usr/bin/python3
def read(f):
  with open(f,"r") as fl: return fl.read();

def readconf(f,delim):
  s = read(f).split("\n")[:-1];
  t = "";
  for i in s:
    i = i.split(delim);
    t += f"global {i[0]}; {i[0]} = {i[1]};\n";
  return t;

def readconfd(f,delim):
  s = read(f).split("\n")[:-1];
  d = dict();
  for i in s:
    i = i.split(delim);
    d[i[0]] = i[1];
  return d;

