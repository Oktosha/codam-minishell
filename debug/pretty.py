import gdb.printing #pyright: ignore[reportMissingModuleSource]

def linked_list_to_str(node_ptr, data_to_str, sep=" "):
  strs = []
  while node_ptr:
    node_val = node_ptr.dereference()
    data = node_val["data"]
    strs.append(data_to_str(data))
    node_ptr = node_val["next"]
  return sep.join(strs)

def str_data_to_str(data):
  str_data = data.cast(gdb.Type.pointer(gdb.lookup_type("char")))
  return str_data.string()

def cmd_data_to_str(data):
  cmd_data = data.cast(gdb.Type.pointer(gdb.lookup_type("t_ps_single_command")))
  return cmd_to_str(cmd_data.dereference())

def cmd_to_str(cmd):
  pid = cmd["pid"]
  argv_str = linked_list_to_str(cmd["argv"], str_data_to_str)
  return (f"{pid}: {argv_str}")

class PsCommandListPrinter:
  def __init__(self, head):
    self.head = head
  def to_string(self):
    return linked_list_to_str(self.head, cmd_data_to_str, " | ")

class PsSingleCommandPrinter:
  def __init__(self, val):
    self.val = val
  def to_string(self):
    return cmd_to_str(self.val)

def kotishell_lookup(val):
  if str(val.type) == "t_ps_single_command":
    return PsSingleCommandPrinter(val)
  if str(val.type) == "t_ps_cmd_node *":
    return PsCommandListPrinter(val)
  return None

class KotishellPrettyPrinter(gdb.printing.PrettyPrinter):
  """
  Simple class for our printers
  """
  def __init__():
    pass

gdb.pretty_printers.append(kotishell_lookup)
