#include "YAPOG/Game/World/Map/Dialog/DialogNode.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogNodeVisitor.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogNodeConstVisitor.hpp"
#include "YAPOG/Game/World/Map/Dialog/DialogNodeEntry.hpp"

namespace yap
{
  DialogNode::DialogNode ()
    : entries_ ()
  {
  }

  DialogNode::~DialogNode ()
  {
    for (DialogNodeEntry* entry : entries_)
      delete entry;
  }

  DialogNode::DialogNode (const DialogNode& copy)
    : entries_ ()
  {
    for (DialogNodeEntry* entry : copy.entries_)
      AddEntry (new DialogNodeEntry (*entry));
  }

  DialogNode* DialogNode::Clone () const
  {
    return new DialogNode (*this);
  }

  DialogNode& DialogNode::AddEntry (DialogNodeEntry* entry)
  {
    entries_.Add (entry);

    return *this;
  }

  bool DialogNode::Accept (IDialogNodeVisitor<bool>& visitor)
  {
    return visitor.VisitDialogNode (*this);
  }

  bool DialogNode::Accept (IDialogNodeConstVisitor<bool>& visitor) const
  {
    return visitor.VisitDialogNode (*this);
  }

  bool DialogNode::Execute (DialogNodeExecutionContext& executionContext)
  {
    for (EntryCollection::SizeType count = 0;
         count < entries_.Count ();
         ++count)
    {
      DialogNodeEntry* entry = entries_[count];

      if (!entry->RequirementIsFulfilled ())
        continue;

      executionContext = DialogNodeExecutionContext (
        ID (count),
        *entry->Message,
        entry->Action,
        entry->NextNode);

      return true;
    }


    return false;
  }
} // namespace yap