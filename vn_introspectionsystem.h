#ifndef VEINNET_INTROSPECTIONSYSTEM_H
#define VEINNET_INTROSPECTIONSYSTEM_H

#include <ve_eventsystem.h>
#include "veinnet_global.h"

#include <QJsonObject>

namespace VeinEvent
{
  class StorageSystem;
}


namespace VeinNet
{
  class VEINNETSHARED_EXPORT IntrospectionSystem : public VeinEvent::EventSystem
  {
    Q_OBJECT
  public:
    explicit IntrospectionSystem(QObject *t_parent=0);

    VeinEvent::StorageSystem *storage() const;
    void setStorage(VeinEvent::StorageSystem *t_storage);

    // EventSystem interface
  public:
    bool processEvent(QEvent *t_event) override;


  private:
    QJsonObject getJsonIntrospection(int t_entityId) const;

    /**
     * @brief The storage determines what entities this system will handle
     * There may be some entities, eg. datatabase synchronized stuff, which should not be introspectable (eg. due to requirements dictated by cross cutting concerns)
     */
    VeinEvent::StorageSystem *m_storage = 0;
  };
} // namespace VeinNet

#endif // VEINNET_INTROSPECTIONSYSTEM_H