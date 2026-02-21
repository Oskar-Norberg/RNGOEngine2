template<std::derived_from<Event> TEvent, typename... Args>
void EventQueue::EmplaceEvent(Args&&... args)
{
    m_events.push_back(std::make_unique<TEvent>(std::forward<Args>(args)...));
}