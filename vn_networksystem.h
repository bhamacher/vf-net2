#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include "veinnet_global.h"

#include <ve_eventsystem.h>

namespace VeinEvent {
  class StorageSystem;
}

namespace VeinNet
{
  class NetworkSystemPrivate;
  class VEINNETSHARED_EXPORT NetworkSystem : public VeinEvent::EventSystem
  {
    Q_OBJECT

  public:
    explicit NetworkSystem(QObject * t_parent=0);
    virtual ~NetworkSystem();

    /**
     * @brief describes whether the events are sent over to no one/subscribers/anyone
     */
    enum OperationMode {
      VNOM_DEBUG =0, /**< do nothing and only print the debug message */
      VNOM_PASS_THROUGH, /**< pass all events to the other site */
      VNOM_SUBCRIPTION /**< [default] only pass events when the other site subscribed to it */
    };

    OperationMode operationMode();
    void setOperationMode(const OperationMode &t_operationMode);

    // EventSystem interface
  public:
    bool processEvent(QEvent *t_event) override;



  private:
    NetworkSystemPrivate *d_ptr = 0;

    Q_DECLARE_PRIVATE(NetworkSystem)
  };
}

#endif // CONNECTIONMANAGER_H
